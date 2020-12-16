#pragma once
#include <Options\GraphOption.h>

class DeleteNodeOption : GraphOption {
public:
	DeleteNodeOption();

	void displayGraphOption(TreeGeneratorVisitor* currentTreeGeneratorVisitor) override;
};