#pragma once
#include <Options\GraphOption.h>

class AddGeodeOption : GraphOption {
public:
	AddGeodeOption();

	void displayGraphOption(TreeGeneratorVisitor* currentTreeGeneratorVisitor) override;
};