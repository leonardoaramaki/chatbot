#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    std::cout << "GraphNode Destructor" << std::endl;
    // if (_chatBot) {
    //     delete _chatBot;
    // }
    //// STUDENT CODE
    ////

    // GraphNode shouldn't have ownership of ChatBot.
    // delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
{
    std::unique_ptr<GraphEdge> p(edge);
    _childEdges.push_back(std::move(p));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot&& chatbot)
{
    _chatBot = new ChatBot();
    ChatBot temp = std::move(chatbot);
    *_chatBot = std::move(temp);
    _chatBot->SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(*_chatBot));
    if (_chatBot) delete _chatBot;
    _chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}