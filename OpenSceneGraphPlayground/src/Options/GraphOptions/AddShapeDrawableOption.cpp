#include "Options\GraphOptions\AddShapeDrawableOption.h"
#include <osg\ShapeDrawable>
#include "UtilityFunctions.h"

AddShapeDrawableOption::AddShapeDrawableOption()
{

}

void AddShapeDrawableOption::displayGraphOption(TreeGeneratorVisitor* currentTreeGeneratorVisitor)
{
	if (ImGui::TreeNode("Add Shape Drawable")) {
		UtilityFunctions::displayImGuiComboBox("Shape to add", typesOfShapes, shapeTypeSelectionIndex);

		//Sphere is selected
		if (shapeTypeSelectionIndex == 0) {
			ImGui::InputFloat3("Position", shapePositionInput);
			ImGui::InputScalar("Radius", ImGuiDataType_Float, &sphereRadiusInput);
			ImGui::ColorEdit4("Sphere Color", shapeColorInput);

			if (ImGui::Button("Add Sphere")) {
				osg::ref_ptr<osg::ShapeDrawable> shapeToAdd = new osg::ShapeDrawable;
				shapeToAdd->setShape(new osg::Sphere(osg::Vec3(shapePositionInput[0], shapePositionInput[1], shapePositionInput[2]), sphereRadiusInput));
				shapeToAdd->setColor(osg::Vec4(shapeColorInput[0], shapeColorInput[1], shapeColorInput[2], shapeColorInput[3]));

				currentTreeGeneratorVisitor->selectedNode->asGeode()->addDrawable(shapeToAdd);
			}
		}

		//Box is selected
		if (shapeTypeSelectionIndex == 1) {
			ImGui::InputFloat3("Position", shapePositionInput);
			ImGui::InputFloat3("Length (X,Y,Z)", boxSizeInput);
			ImGui::ColorEdit4("Box Color", shapeColorInput);

			if (ImGui::Button("Add Box")) {
				osg::ref_ptr<osg::ShapeDrawable> shapeToAdd = new osg::ShapeDrawable;
				shapeToAdd->setShape(new osg::Box(osg::Vec3(shapePositionInput[0], shapePositionInput[1], shapePositionInput[2]), boxSizeInput[0], boxSizeInput[1], boxSizeInput[2]));
				shapeToAdd->setColor(osg::Vec4(shapeColorInput[0], shapeColorInput[1], shapeColorInput[2], shapeColorInput[3]));

				currentTreeGeneratorVisitor->selectedNode->asGeode()->addDrawable(shapeToAdd);
			}
		}

		//Cone is selected
		if (shapeTypeSelectionIndex == 2) {
			ImGui::InputFloat3("Position", shapePositionInput);
			ImGui::InputScalar("Radius", ImGuiDataType_Float, &coneRadiusInput);
			ImGui::InputScalar("Height", ImGuiDataType_Float, &coneHeightInput);
			ImGui::ColorEdit4("Cone Color", shapeColorInput);

			if (ImGui::Button("Add Cone")) {
				osg::ref_ptr<osg::ShapeDrawable> shapeToAdd = new osg::ShapeDrawable;
				shapeToAdd->setShape(new osg::Cone(osg::Vec3(shapePositionInput[0], shapePositionInput[1], shapePositionInput[2]), coneRadiusInput, coneHeightInput));
				shapeToAdd->setColor(osg::Vec4(shapeColorInput[0], shapeColorInput[1], shapeColorInput[2], shapeColorInput[3]));

				currentTreeGeneratorVisitor->selectedNode->asGeode()->addDrawable(shapeToAdd);
			}
		}

		ImGui::TreePop();
	}
}
