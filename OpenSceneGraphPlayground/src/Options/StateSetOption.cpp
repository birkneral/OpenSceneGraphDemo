#include "Options\StateSetOption.h"
#include <osg\BlendFunc>

StateSetOption::StateSetOption()
{
	glConstToStringMap[GL_POINT] = "GL_POINT";
	glConstToStringMap[GL_LINE] = "GL_LINE";
	glConstToStringMap[GL_FILL] = "GL_FILL";

	glConstToStringMap[GL_DST_ALPHA] = "GL_DST_ALPHA";
	glConstToStringMap[GL_DST_COLOR] = "GL_DST_COLOR";
	glConstToStringMap[GL_ONE] = "GL_ONE";
	glConstToStringMap[GL_ONE_MINUS_DST_ALPHA] = "GL_ONE_MINUS_DST_ALPHA";
	glConstToStringMap[GL_ONE_MINUS_DST_COLOR] = "GL_ONE_MINUS_DST_COLOR";
	glConstToStringMap[GL_ONE_MINUS_SRC_ALPHA] = "GL_ONE_MINUS_SRC_ALPHA";
	glConstToStringMap[GL_ONE_MINUS_SRC_COLOR] = "GL_ONE_MINUS_SRC_COLOR";
	glConstToStringMap[GL_SRC_ALPHA] = "GL_SRC_ALPHA";
	glConstToStringMap[GL_SRC_ALPHA_SATURATE] = "GL_SRC_ALPHA_SATURATE";
	glConstToStringMap[GL_SRC_COLOR] = "GL_SRC_COLOR";
	glConstToStringMap[GL_CONSTANT_COLOR] = "GL_CONSTANT_COLOR";
	glConstToStringMap[GL_ONE_MINUS_CONSTANT_COLOR] = "GL_ONE_MINUS_CONSTANT_COLOR";
	glConstToStringMap[GL_CONSTANT_ALPHA] = "GL_CONSTANT_ALPHA";
	glConstToStringMap[GL_ONE_MINUS_CONSTANT_ALPHA] = "GL_ONE_MINUS_CONSTANT_ALPHA";
	glConstToStringMap[GL_ZERO] = "GL_ZERO";

	glConstToStringMap[GL_FLOAT] = "GL_Float";
	glConstToStringMap[GL_FLOAT_VEC2] = "GL_FLOAT_VEC2";
	glConstToStringMap[GL_FLOAT_VEC3] = "GL_FLOAT_VEC3";
	glConstToStringMap[GL_FLOAT_VEC4] = "GL_FLOAT_VEC4";
	glConstToStringMap[GL_INT] = "GL_INT";
	glConstToStringMap[GL_UNSIGNED_INT] = "GL_UNSIGNED_INT";
	glConstToStringMap[GL_FLOAT_MAT2] = "GL_FLOAT_MAT2";
	glConstToStringMap[GL_FLOAT_MAT3] = "GL_FLOAT_MAT3";
	glConstToStringMap[GL_FLOAT_MAT4] = "GL_FLOAT_MAT4";

	selectionIdToStateAttributeFlag[0] = osg::StateAttribute::Values::OVERRIDE;
	selectionIdToStateAttributeFlag[1] = osg::StateAttribute::Values::PROTECTED;
	selectionIdToStateAttributeFlag[2] = osg::StateAttribute::Values::INHERIT;

	selectionIdToStateAttributeModeOnOff[0] = osg::StateAttribute::Values::ON;
	selectionIdToStateAttributeModeOnOff[1] = osg::StateAttribute::Values::OFF;

	stateAttributeFlagToString[osg::StateAttribute::ON] = "ON";
	stateAttributeFlagToString[osg::StateAttribute::OFF] = "OFF";
	stateAttributeFlagToString[osg::StateAttribute::OVERRIDE] = "OVERIDE";
	stateAttributeFlagToString[osg::StateAttribute::ON + osg::StateAttribute::OVERRIDE] = "ON + OVERIDE";
	stateAttributeFlagToString[osg::StateAttribute::PROTECTED] = "PROTECTED";
	stateAttributeFlagToString[osg::StateAttribute::ON + osg::StateAttribute::PROTECTED] = "ON + PROTECTED";
	stateAttributeFlagToString[osg::StateAttribute::INHERIT] = "INHERIT";
	stateAttributeFlagToString[osg::StateAttribute::ON + osg::StateAttribute::INHERIT] = "ON + INHERIT";
}
