#pragma once
#include <Options\GraphOption.h>

class AddOrAdjustSwitchNodeOption : GraphOption {
public:
	AddOrAdjustSwitchNodeOption();

	void displayGraphOption(TreeGeneratorVisitor* currentTreeGeneratorVisitor) override;
};