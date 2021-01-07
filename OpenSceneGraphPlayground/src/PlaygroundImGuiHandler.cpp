#include "PlaygroundImGuiHandler.h"
#include <imgui\imgui.h>
#include <filesystem>
#include <iostream>

#include <osgGA/TrackballManipulator>
#include <osg/ShapeDrawable>
#include <osg/Geode>

PlaygroundImGuiHandler::PlaygroundImGuiHandler(osg::ref_ptr<osgViewer::Viewer> viewer, osg::ref_ptr<osg::Group> rootNode)
{
	this->viewer = viewer;
	this->rootNode = rootNode;
	nodeTrackballManipulator = new osgGA::NodeTrackerManipulator;
	viewer->setCameraManipulator(nodeTrackballManipulator);
}

void PlaygroundImGuiHandler::drawUi()
{	
	IM_ASSERT(ImGui::GetCurrentContext() != NULL && "Missing dear imgui context. Please fix dependencies.");
	//ImGui::ShowDemoWindow();

	//ImGui::NewFrame();
	ImGui::SetWindowSize(ImVec2(100, 300));
	ImGui::Begin("Editor:");

	if (ImGui::CollapsingHeader("Adjust Scene Graph")) {

		ImGui::Text("Current Scene Graph:");

		treeGeneratorVisitor.rootNode = this->rootNode;
		//Creates the tree with all nodes
		rootNode->accept(treeGeneratorVisitor);

		ImGui::Separator();

		ImGui::Text("Selected Node: ");
		if (treeGeneratorVisitor.selectedNode != NULL && treeGeneratorVisitor.selectedNodeName != "") {
			ImGui::SameLine();
			ImGui::Text(treeGeneratorVisitor.selectedNodeName.c_str());
		}

		ImGui::Separator();

		ImGui::Text("Options:");

		if (treeGeneratorVisitor.selectedNodeIsGroup) {
			addGeodeOption.displayGraphOption(&treeGeneratorVisitor);
			addGroupOption.displayGraphOption(&treeGeneratorVisitor);
			addNodeFromFileOption.displayGraphOption(&treeGeneratorVisitor);
			addLightSourceOption.displayGraphOption(&treeGeneratorVisitor);
			addMatrixTransformOption.displayGraphOption(&treeGeneratorVisitor);
			addOrAdjustSwitchNodeOption.displayGraphOption(&treeGeneratorVisitor);
			addOrAdjustLodNodeOption.displayGraphOption(&treeGeneratorVisitor);
			adjustStateOption.displayStateSetOption(treeGeneratorVisitor.selectedNode->getOrCreateStateSet());
		}

		if (treeGeneratorVisitor.selectedNodeIsGeode) {
			addShapeDrawableOption.displayGraphOption(&treeGeneratorVisitor);
			addGeometryOption.displayGraphOption(&treeGeneratorVisitor);
			addIndexedGeometryOption.displayGraphOption(&treeGeneratorVisitor);
			addMatrixTransformOption.displayGraphOption(&treeGeneratorVisitor);
			adjustStateOption.displayStateSetOption(treeGeneratorVisitor.selectedNode->getOrCreateStateSet());
		}

		if (treeGeneratorVisitor.selectedNodeIsDrawable) {
			adjustStateOption.displayStateSetOption(treeGeneratorVisitor.selectedNode->getOrCreateStateSet());
		}

		if (treeGeneratorVisitor.selectedNode != NULL && treeGeneratorVisitor.selectedNode.get() != rootNode.get()) {
			deleteNodeOption.displayGraphOption(&treeGeneratorVisitor);
		}

		ImGui::Separator();
	}

	if (ImGui::CollapsingHeader("Change View")) {
		if (treeGeneratorVisitor.selectedNode != NULL) {
			if (ImGui::Button("Focus Currently Selected Node")) {
				nodeTrackballManipulator->setNode(treeGeneratorVisitor.selectedNode.get());
			}
		}

		ImGui::ColorEdit3("Background Color", backgroundColorInput);
		
		if (ImGui::Button("Change Background Color")) {
			viewer->getCamera()->setClearColor(osg::Vec4(backgroundColorInput[0], backgroundColorInput[1], backgroundColorInput[2], 1.0f));
		}
	}

	ImGui::End();

	treeGeneratorVisitor.resetCounter();
}