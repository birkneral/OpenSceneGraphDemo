#include "Options\GraphOptions\AddLightSourceOption.h"
#include <osg\LightSource>
#include "UtilityFunctions.h"

AddLightSourceOption::AddLightSourceOption()
{
}

void AddLightSourceOption::displayGraphOption(TreeGeneratorVisitor* currentTreeGeneratorVisitor)
{
	if (ImGui::TreeNode("Add Light Source")) {

		UtilityFunctions::displayImGuiComboBox("Shape to Add", lightSourceTypes, lightSourceTypeSelectionIndex);

		//Only 8 light sources are supported
		if (currentTreeGeneratorVisitor->currentLightCounter < 8) {
			ImGui::Checkbox("Overwrite Default Light", &overwriteDefaultLightInput);

			//Directional is selected
			if (lightSourceTypeSelectionIndex == 0) {
				ImGui::InputFloat3("Direction", lightDirectionInput);
				ImGui::ColorEdit4("Diffuse Light Color", diffuseLightColorInput);
				ImGui::ColorEdit4("Ambient Light Color", ambientLightColorInput);

				if (ImGui::Button("Add Light")) {
					osg::ref_ptr<osg::Light> lightToAdd = new osg::Light;

					if (overwriteDefaultLightInput) {
						lightToAdd->setLightNum(0);
						currentTreeGeneratorVisitor->defaultLightSourceIsOverwritten = true;
					}
					else {
						lightToAdd->setLightNum(currentTreeGeneratorVisitor->currentLightCounter);
					}

					lightToAdd->setDiffuse(osg::Vec4(diffuseLightColorInput[0], diffuseLightColorInput[1], diffuseLightColorInput[2], diffuseLightColorInput[3]));
					lightToAdd->setAmbient(osg::Vec4(ambientLightColorInput[0], ambientLightColorInput[1], ambientLightColorInput[2], ambientLightColorInput[3]));
					lightToAdd->setDirection(osg::Vec3(lightDirectionInput[0], lightDirectionInput[1], lightDirectionInput[2]));
					//Zero at fourth position indicates OSG that it is a directional light
					lightToAdd->setPosition(osg::Vec4(0.0f, 0.0f, 0.0f, 0.0f));

					osg::ref_ptr<osg::LightSource> lightSourceToAdd = new osg::LightSource;
					lightSourceToAdd->setLight(lightToAdd);

					currentTreeGeneratorVisitor->selectedNode->asGroup()->addChild(lightSourceToAdd);
				}
			}

			//Directional is selected
			if (lightSourceTypeSelectionIndex == 1) {
				ImGui::InputFloat3("Position", lightPositionInput);
				ImGui::ColorEdit4("Diffuse Light Color", diffuseLightColorInput);
				ImGui::ColorEdit4("Ambient Light Color", ambientLightColorInput);

				if (ImGui::Button("Add Light")) {
					osg::ref_ptr<osg::Light> lightToAdd = new osg::Light;

					if (overwriteDefaultLightInput) {
						lightToAdd->setLightNum(0);
						currentTreeGeneratorVisitor->defaultLightSourceIsOverwritten = true;
					}
					else {
						lightToAdd->setLightNum(currentTreeGeneratorVisitor->currentLightCounter);
					}

					lightToAdd->setDiffuse(osg::Vec4(diffuseLightColorInput[0], diffuseLightColorInput[1], diffuseLightColorInput[2], diffuseLightColorInput[3]));
					lightToAdd->setAmbient(osg::Vec4(ambientLightColorInput[0], ambientLightColorInput[1], ambientLightColorInput[2], ambientLightColorInput[3]));
					lightToAdd->setPosition(osg::Vec4(lightPositionInput[0], lightPositionInput[1], lightPositionInput[2], 1.0f));

					osg::ref_ptr<osg::LightSource> lightSourceToAdd = new osg::LightSource;
					lightSourceToAdd->setLight(lightToAdd);

					currentTreeGeneratorVisitor->selectedNode->asGroup()->addChild(lightSourceToAdd);
				}
			}
		}
		else {
			ImGui::Text("No more light sources can be added.\nOnly eight are supported.");
		}

		ImGui::TreePop();
	}
}
