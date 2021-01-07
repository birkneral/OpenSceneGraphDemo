#pragma once
#include "TreeGeneratorVisitor.h"
#include <string>

class StateSetOption {
public:
	StateSetOption();

	virtual void displayStateSetOption(osg::ref_ptr<osg::StateSet> stateSetOfCurrentlySelectedNode) = 0;
protected:
	std::vector<std::string> availableFlags = { "OVERRIDE", "PROTECTED", "INHERITAT" };
	std::vector<std::string> onOffSelections = { "ON", "OFF" };

	std::map<int, std::string> glConstToStringMap;
	std::map<unsigned int, std::string> stateAttributeFlagToString;
	std::map<unsigned int, std::string> stateAttributeOnOffToString;

	std::map<int, osg::StateAttribute::Values> selectionIdToStateAttributeFlag;
	std::map<int, osg::StateAttribute::Values> selectionIdToStateAttributeModeOnOff;

};