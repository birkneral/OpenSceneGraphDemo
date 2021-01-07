#include "Options\GraphOptions\AddGeometryOption.h" 
#include <osg\Geometry>
#include <osgUtil\SmoothingVisitor>

AddGeometryOption::AddGeometryOption()
{
	setTriangleAsInputData();
}

void AddGeometryOption::displayGraphOption(TreeGeneratorVisitor* currentTreeGeneratorVisitor)
{
	if (ImGui::TreeNode("Add Geometry")) {

		for (int i = 0; i < inputVertices.size(); i++)
		{
			std::string inputLabel = "Vertex " + std::to_string(i);
			ImGui::InputFloat3(inputLabel.c_str(), inputVertices[i]);
		}

		if (ImGui::Button("Add Vertex")) {
			inputVertices.push_back(new float[3]{ 0.0f, 0.0f, 0.0f });
		}

		if (inputVertices.size() > 1) {
			ImGui::SameLine();
			if (ImGui::Button("Remove Last Vertex")) {
				float* arrayToDelete = inputVertices.at(inputVertices.size() - 1);
				delete(arrayToDelete);
				inputVertices.pop_back();
			}
		}

		ImGui::ColorEdit4("Geometry Color", geometryColorInput);

		if (inputVertices.size() % 3 == 0) {
			if (ImGui::Button("Add Geometry")) {
				colors = new osg::Vec4Array;
				colors->push_back(osg::Vec4(geometryColorInput[0], geometryColorInput[1], geometryColorInput[2], geometryColorInput[3]));

				osg::ref_ptr<osg::Geometry> geometryToAdd = new osg::Geometry;

				if (!vertices->empty()) {
					vertices->clear();
				}

				for (int i = 0; i < inputVertices.size(); i++)
				{
					vertices->push_back((osg::Vec3(inputVertices[i][0], inputVertices[i][1], inputVertices[i][2])));
				}

				geometryToAdd->setVertexArray(vertices.get());
				geometryToAdd->setColorArray(colors.get());
				geometryToAdd->setColorBinding(osg::Geometry::BIND_OVERALL);

				geometryToAdd->addPrimitiveSet(new osg::DrawArrays(GL_TRIANGLES, 0, vertices->size()));

				//Calculates normals for geometryToAdd
				osgUtil::SmoothingVisitor::smooth(*geometryToAdd);

				currentTreeGeneratorVisitor->selectedNode->asGeode()->addDrawable(geometryToAdd);
			}
		}
		else {
			ImGui::Text("Please use input vertex amount\nthat is dividable by three");
		}
		
		ImGui::TreePop();
	}
}

void AddGeometryOption::setTriangleAsInputData()
{
	inputVertices.push_back(new float[3]{ -1.0f, 0.0f, 0.0f });
	inputVertices.push_back(new float[3]{ 1.0f, 0.0f, 0.0f });
	inputVertices.push_back(new float[3]{ 0.0f, 0.0f, 1.0f });
}
