#pragma once
#include <Options\GraphOption.h>


class AddGeometryOption : GraphOption {
public:
	AddGeometryOption();

	void displayGraphOption(TreeGeneratorVisitor* currentTreeGeneratorVisitor) override;

private:
	void setTriangleAsInputData();

	std::vector<float*> inputVertices;

	float geometryColorInput[4] = { 1.0f, 0.0f, 0.0f, 1.0f };

	osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
	osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
};