#pragma once
#include "windows.h"
#include <osg\NodeVisitor>
#include <osg\Geode>
#include <imgui\imgui.h>

class TreeGeneratorVisitor : public osg::NodeVisitor {
public:
	TreeGeneratorVisitor();
	
	void resetCounter();
	void resetSelection();

	virtual void apply(osg::Group& node);
	virtual void apply(osg::Geode& geode);
	virtual void apply(osg::Drawable& drawable);

	osg::ref_ptr<osg::Node> rootNode;
	osg::ref_ptr<osg::Node> selectedNode;

	unsigned int completeNodeCounter = 0;

	unsigned int currentLightCounter = 0;
	bool defaultLightSourceIsOverwritten = false;

	bool selectedNodeIsGroup = false;
	bool selectedNodeIsGeode = false;
	bool selectedNodeIsDrawable = false;
	std::string selectedNodeName = "";

	ImGuiTreeNodeFlags base_tree_node_flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick | ImGuiTreeNodeFlags_SpanAvailWidth;
};