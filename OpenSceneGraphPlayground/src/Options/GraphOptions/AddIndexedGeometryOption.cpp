#include "Options\GraphOptions\AddIndexedGeometryOption.h"
#include <osg\Geometry>
#include <osgUtil\SmoothingVisitor>

AddIndexedGeometryOption::AddIndexedGeometryOption()
{
	loadDataForOctahedron();
}

void AddIndexedGeometryOption::displayGraphOption(TreeGeneratorVisitor* currentTreeGeneratorVisitor)
{
	if (ImGui::TreeNode("Add Indexed Geometry")) {
		ImGui::ColorEdit4("Geometry Color", geometryColorInput);
		if (ImGui::Button("Add Indexed Geometry")) {
			colors = new osg::Vec4Array;
			colors->push_back(osg::Vec4(geometryColorInput[0], geometryColorInput[1], geometryColorInput[2], geometryColorInput[3]));

			osg::ref_ptr<osg::Geometry> geometryToAdd = new osg::Geometry;
			geometryToAdd->setVertexArray(vertices.get());
			geometryToAdd->addPrimitiveSet(indices.get());
			geometryToAdd->setColorArray(colors.get());
			geometryToAdd->setColorBinding(osg::Geometry::BIND_OVERALL);

			//Calculates normals for geometryToAdd
			osgUtil::SmoothingVisitor::smooth(*geometryToAdd);

			currentTreeGeneratorVisitor->selectedNode->asGeode()->addDrawable(geometryToAdd);
		}

		ImGui::TreePop();
	}
}

void AddIndexedGeometryOption::loadDataForOctahedron()
{
	vertices = new osg::Vec3Array;
	vertices->push_back(osg::Vec3(0.0f, 0.0f, 1.0f));
	vertices->push_back(osg::Vec3(-0.5f, -0.5f, 0.0f));
	vertices->push_back(osg::Vec3(0.5f, -0.5f, 0.0f));
	vertices->push_back(osg::Vec3(0.5f, 0.5f, 0.0f));
	vertices->push_back(osg::Vec3(-0.5f, 0.5f, 0.0f));
	vertices->push_back(osg::Vec3(0.0f, 0.0f, -1.0f));

	indices = new osg::DrawElementsUInt(GL_TRIANGLES, 24);
	(*indices)[0] = 0; (*indices)[1] = 1; (*indices)[2] = 2;
	(*indices)[3] = 0; (*indices)[4] = 2; (*indices)[5] = 3;
	(*indices)[6] = 0; (*indices)[7] = 3; (*indices)[8] = 4;
	(*indices)[9] = 0; (*indices)[10] = 4; (*indices)[11] = 1;
	(*indices)[12] = 5; (*indices)[13] = 2; (*indices)[14] = 1;
	(*indices)[15] = 5; (*indices)[16] = 3; (*indices)[17] = 2;
	(*indices)[18] = 5; (*indices)[19] = 4; (*indices)[20] = 3;
	(*indices)[21] = 5; (*indices)[22] = 1; (*indices)[23] = 4;
}
