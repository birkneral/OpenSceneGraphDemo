#pragma once
#include <iostream>
#include "windows.h"
#include "GL/glew.h"

#include "OsgImGuiHandler.hpp"


class GlewInitOperation : public osg::Operation {
 
public:
    GlewInitOperation() : osg::Operation("GlewInitCallback", false) {};

    void operator()(osg::Object* object) override
    {
        osg::GraphicsContext* context = dynamic_cast<osg::GraphicsContext*>(object);
        if (!context)
            return;

        if (glewInit() != GLEW_OK)
        {
            std::cout << "glewInit() failed\n";
        }
    }
};