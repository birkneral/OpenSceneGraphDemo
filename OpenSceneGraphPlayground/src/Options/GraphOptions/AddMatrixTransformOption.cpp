#include "Options\GraphOptions\AddMatrixTransformOption.h"
#include <osg\MatrixTransform>
#include "UtilityFunctions.h"

AddMatrixTransformOption::AddMatrixTransformOption()
{
}

void AddMatrixTransformOption::displayGraphOption(TreeGeneratorVisitor* currentTreeGeneratorVisitor)
{
	if (ImGui::TreeNode("Add Matrix Transform")) {
		UtilityFunctions::displayImGuiComboBox("Type of Transform", transformationTypes, transformTypeSelectionIndex);

		//Translation is selected
		if (transformTypeSelectionIndex == 0) {
			ImGui::InputFloat3("Translate Values", translationVectorInput);

			if (currentTreeGeneratorVisitor->selectedNode.get() != currentTreeGeneratorVisitor->rootNode.get()) {
				if (ImGui::Button("Add MatrixTransform as Parent")) {
					osg::ref_ptr<osg::MatrixTransform> transformationNodeToAdd = generateTranslateMatrixTransformNode();
					addNodeAsParent(currentTreeGeneratorVisitor, transformationNodeToAdd);
				}
			}
			if (!currentTreeGeneratorVisitor->selectedNodeIsGeode) {
				if (ImGui::Button("Add MatrixTransform as Child")) {
					osg::ref_ptr<osg::MatrixTransform> transformationNodeToAdd = generateTranslateMatrixTransformNode();
					currentTreeGeneratorVisitor->selectedNode->asGroup()->addChild(transformationNodeToAdd);
				}
			}
		}

		//Rotation is selected
		if (transformTypeSelectionIndex == 1) {
			ImGui::InputScalar("Rotation Angle", ImGuiDataType_Float, &rotationAngleInput);
			ImGui::InputFloat3("Rotation Axis", rotationAxisInput);

			if (currentTreeGeneratorVisitor->selectedNode.get() != currentTreeGeneratorVisitor->rootNode.get()) {
				if (ImGui::Button("Add MatrixTransform as Parent")) {
					osg::ref_ptr<osg::MatrixTransform> transformationNodeToAdd = generateRotateMatrixTransformNode();
					addNodeAsParent(currentTreeGeneratorVisitor, transformationNodeToAdd);
				}
			}
			if (!currentTreeGeneratorVisitor->selectedNodeIsGeode) {
				if (ImGui::Button("Add MatrixTransform as Child")) {
					osg::ref_ptr<osg::MatrixTransform> transformationNodeToAdd = generateRotateMatrixTransformNode();
					currentTreeGeneratorVisitor->selectedNode->asGroup()->addChild(transformationNodeToAdd);
				}
			}
		}

		//Scale is selected
		if (transformTypeSelectionIndex == 2) {
			ImGui::InputFloat3("Scale Values", scaleVectorInput);

			if (currentTreeGeneratorVisitor->selectedNode.get() != currentTreeGeneratorVisitor->rootNode.get()) {
				if (ImGui::Button("Add MatrixTransform as Parent")) {
					osg::ref_ptr<osg::MatrixTransform> transformationNodeToAdd = generateSclaeMatrixTransformNode();
					addNodeAsParent(currentTreeGeneratorVisitor, transformationNodeToAdd);
				}
			}
			if (!currentTreeGeneratorVisitor->selectedNodeIsGeode) {
				if (ImGui::Button("Add MatrixTransform as Child")) {
					osg::ref_ptr<osg::MatrixTransform> transformationNodeToAdd = generateSclaeMatrixTransformNode();
					currentTreeGeneratorVisitor->selectedNode->asGroup()->addChild(transformationNodeToAdd);
				}
			}
		}

		ImGui::TreePop();
	}
}

void AddMatrixTransformOption::addNodeAsParent(TreeGeneratorVisitor* currentTreeGeneratorVisitor, osg::ref_ptr<osg::MatrixTransform> matrixTransformNodeToAdd)
{
	matrixTransformNodeToAdd->addChild(currentTreeGeneratorVisitor->selectedNode);

	osg::ref_ptr<osg::Group> parentNode = currentTreeGeneratorVisitor->selectedNode->getParent(0);
	parentNode->removeChild(currentTreeGeneratorVisitor->selectedNode);
	parentNode->addChild(matrixTransformNodeToAdd);
}

osg::ref_ptr<osg::MatrixTransform> AddMatrixTransformOption::generateTranslateMatrixTransformNode()
{
	osg::ref_ptr<osg::MatrixTransform> transformationNodeToAdd = new osg::MatrixTransform;
	transformationNodeToAdd->setMatrix(osg::Matrix::translate(translationVectorInput[0], translationVectorInput[1], translationVectorInput[2]));
	return transformationNodeToAdd;
}

osg::ref_ptr<osg::MatrixTransform> AddMatrixTransformOption::generateRotateMatrixTransformNode()
{
	osg::ref_ptr<osg::MatrixTransform> transformationNodeToAdd = new osg::MatrixTransform;
	transformationNodeToAdd->setMatrix(osg::Matrix::rotate(rotationAngleInput, osg::Vec3(rotationAxisInput[0], rotationAxisInput[1], rotationAxisInput[2])));
	return transformationNodeToAdd;
}

osg::ref_ptr<osg::MatrixTransform> AddMatrixTransformOption::generateSclaeMatrixTransformNode()
{
	osg::ref_ptr<osg::MatrixTransform> transformationNodeToAdd = new osg::MatrixTransform;
	transformationNodeToAdd->setMatrix(osg::Matrix::scale(osg::Vec3(scaleVectorInput[0], scaleVectorInput[1], scaleVectorInput[2])));
	return transformationNodeToAdd;
}

