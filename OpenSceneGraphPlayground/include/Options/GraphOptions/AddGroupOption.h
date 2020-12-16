#pragma once
#include <Options\GraphOption.h>

class AddGroupOption : GraphOption {
public:
	AddGroupOption();

	void displayGraphOption(TreeGeneratorVisitor* currentTreeGeneratorVisitor) override;
};