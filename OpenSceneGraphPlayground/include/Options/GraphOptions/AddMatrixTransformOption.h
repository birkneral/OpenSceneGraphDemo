#pragma once
#include <Options\GraphOption.h>

class AddMatrixTransformOption : GraphOption {
public:
	AddMatrixTransformOption();

	void displayGraphOption(TreeGeneratorVisitor* currentTreeGeneratorVisitor) override;
private:
	void addNodeAsParent(TreeGeneratorVisitor* currentTreeGeneratorVisitor, osg::ref_ptr<osg::MatrixTransform> matrixTransformNodeToAdd);

	osg::ref_ptr<osg::MatrixTransform> generateTranslateMatrixTransformNode();
	osg::ref_ptr<osg::MatrixTransform> generateRotateMatrixTransformNode();
	osg::ref_ptr<osg::MatrixTransform> generateSclaeMatrixTransformNode();

	const char* transformationTypes[3] = { "Translation", "Rotation", "Scale" };

	int transformTypeSelectionIndex = 0;

	float translationVectorInput[3] = { 0.0f, 0.0f, 0.0f };

	float rotationAxisInput[3] = { 1.0f, 0.0f, 0.0f };
	float rotationAngleInput = 45.0f;

	float scaleVectorInput[3] = { 1.0f, 1.0f, 1.0f };
};