#include "TreeGeneratorVisitor.h"
#include <imgui\imgui.h>

TreeGeneratorVisitor::TreeGeneratorVisitor()
{
    setTraversalMode(osg::NodeVisitor::TRAVERSE_ALL_CHILDREN);
}

void TreeGeneratorVisitor::apply(osg::Group& group)
{
    completeNodeCounter++;
    std::string groupesDisplayNameInTree;
    groupesDisplayNameInTree.append(group.className());

    if (groupesDisplayNameInTree == "Light Source") {
        currentLightCounter++;
    }

    ImGuiTreeNodeFlags node_flags = base_tree_node_flags;
    if (selectedNode.get() == group.asNode()) {
        node_flags |= ImGuiTreeNodeFlags_Selected;
    }

    bool nodeOpen = ImGui::TreeNodeEx((void*)(intptr_t)completeNodeCounter, node_flags, groupesDisplayNameInTree.c_str());

    //Check if item was selected, excluding the click on the arrow
    if (ImGui::IsItemClicked() && (ImGui::GetMousePos().x - ImGui::GetItemRectMin().x) > ImGui::GetTreeNodeToLabelSpacing())
    {
        resetSelection();
        selectedNodeIsGroup = true;
        selectedNode = group.asNode();
        selectedNodeName = groupesDisplayNameInTree;
    }
    if(nodeOpen){
        traverse(group);
        ImGui::TreePop();
    }
}

void TreeGeneratorVisitor::apply(osg::Geode& geode)
{
    completeNodeCounter++;
    std::string geodesDisplayNameInTree;
    geodesDisplayNameInTree.append(geode.className());

    ImGuiTreeNodeFlags node_flags = base_tree_node_flags;
    if (selectedNode.get() == geode.asNode()) {
        node_flags |= ImGuiTreeNodeFlags_Selected;
    }

    bool nodeOpen = ImGui::TreeNodeEx((void*)(intptr_t)completeNodeCounter, node_flags, geodesDisplayNameInTree.c_str());

    //Check if item was selected, excluding the click on the arrow
    if (ImGui::IsItemClicked() && (ImGui::GetMousePos().x - ImGui::GetItemRectMin().x) > ImGui::GetTreeNodeToLabelSpacing())
    {
        resetSelection();
        selectedNodeIsGeode = true;
        selectedNode = geode.asNode();
        selectedNodeName = geodesDisplayNameInTree;
    }
    if (nodeOpen) {
        traverse(geode);
        ImGui::TreePop();
    }
}

void TreeGeneratorVisitor::apply(osg::Drawable& drawable)
{
    completeNodeCounter++;
    std::string drawablesDisplayNameInTree;
    drawablesDisplayNameInTree.append(drawable.className());

    ImGuiTreeNodeFlags node_flags = base_tree_node_flags;
    node_flags |= ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen | ImGuiTreeNodeFlags_Bullet;
    if (selectedNode.get() == drawable.asNode()) {
        node_flags |= ImGuiTreeNodeFlags_Selected;
    }

    bool nodeOpen = ImGui::TreeNodeEx((void*)(intptr_t)completeNodeCounter, node_flags, drawablesDisplayNameInTree.c_str());

    //Check if item was selected, excluding the click on the arrow
    if (ImGui::IsItemClicked() && (ImGui::GetMousePos().x - ImGui::GetItemRectMin().x) > ImGui::GetTreeNodeToLabelSpacing())
    {
        resetSelection();
        selectedNodeIsDrawable = true;
        selectedNode = drawable.asNode();
        selectedNodeName = drawablesDisplayNameInTree;
    }

    traverse(drawable);
}

void TreeGeneratorVisitor::resetCounter()
{
    completeNodeCounter = 0;
    if (defaultLightSourceIsOverwritten) {
        currentLightCounter = 0;
    }
    else {
        currentLightCounter = 1;
    }
}

void TreeGeneratorVisitor::resetSelection()
{
    selectedNodeIsGeode = false;
    selectedNodeIsGroup = false;
    selectedNodeIsDrawable = false;
    selectedNodeName = "";
    selectedNode = NULL;
}



//void TreeGeneratorVisitor::apply(osg::Node& group)
//{
//    nodeNames.push_back(spaces() + group.libraryName() + "::" + group.className());
//    _level++;
//    traverse(group);
//    _level--;
//}
//
//void TreeGeneratorVisitor::apply(osg::Geode& geode)
//{
//    nodeNames.push_back(spaces() + geode.libraryName() + "::" + geode.className());
//
//    _level++;
//
//    for (unsigned int i = 0; i < geode.getNumDrawables(); i++) {
//        osg::Drawable* drawable = geode.getDrawable(i);
//        nodeNames.push_back(spaces() + drawable->libraryName() + "::" + drawable->className());
//    }
//
//    traverse(geode);
//    _level--;
//}


