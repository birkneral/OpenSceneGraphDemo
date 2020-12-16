#pragma once
#include "TreeGeneratorVisitor.h"
#include <string>

class StateSetOption {
public:
	StateSetOption();

	virtual void displayStateSetOption(TreeGeneratorVisitor* currentTreeGeneratorVisitor) = 0;
protected:
	const char* availableFlags[3] = { "OVERRIDE", "PROTECTED", "INHERITAT" };
	const char* onOffSelections[2] = { "ON", "OFF" };

	std::map<int, std::string> glConstToStringMap;
	std::map<unsigned int, std::string> stateAttributeFlagToString;
	std::map<unsigned int, std::string> stateAttributeOnOffToString;

	std::map<int, osg::StateAttribute::Values> selectionIdToStateAttributeFlag;
	std::map<int, osg::StateAttribute::Values> selectionIdToStateAttributeModeOnOff;

};