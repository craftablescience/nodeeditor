#include "FlowScene.hpp"

#include "FlowItem.hpp"
#include "FlowItemInterface.hpp"

FlowScene* FlowScene::_instance = nullptr;

FlowScene*
FlowScene::
instance()
{
  if (_instance == nullptr)
    _instance = new FlowScene();

  return _instance;
}

void
FlowScene::
registerFlowItem(FlowItemInterface* flowItemIterface)
{
  //
}

QUuid
FlowScene::
createConnection(QUuid flowItemID, Connection::Dragging dragging)
{
  Connection* connection = nullptr;

  switch (dragging) {
    case Connection::SOURCE:
      // we are dragging source, it gets zero Uuid
      connection = new Connection(QUuid(), flowItemID);

      break;

    case Connection::SINK:
      connection = new Connection(flowItemID, QUuid());

      break;

    default:
      break;
  }

  this->addItem(connection);
  _connections[connection->id()] = connection;
}

QUuid
FlowScene::
createFlowItem()
{
  FlowItem* flowItem = new FlowItem();

  this->addItem(flowItem);
  _flowItems[flowItem->id()] = flowItem;
}

FlowScene::
FlowScene()
{
  //
}