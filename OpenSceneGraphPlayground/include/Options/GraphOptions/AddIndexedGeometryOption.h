#pragma once
#include <Options\GraphOption.h>


class AddIndexedGeometryOption : GraphOption {
public:
	AddIndexedGeometryOption();

	void displayGraphOption(TreeGeneratorVisitor* currentTreeGeneratorVisitor) override;
private:
	void loadDataForOctahedron();

	float geometryColorInput[4] = { 1.0f, 0.0f, 0.0f, 1.0f };

	osg::ref_ptr<osg::Vec3Array> vertices;
	osg::ref_ptr<osg::Vec4Array> colors;
	osg::ref_ptr<osg::DrawElementsUInt> indices;
};