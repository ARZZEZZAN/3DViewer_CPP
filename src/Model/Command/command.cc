#include "command.h"

namespace s21 {
// class Invoker
void Invoker::Execute(Command* command, Operation operation, double value) {
  command->Execute(operation, value);
  delete command;
}

// class RotateCommand
RotateCommand::RotateCommand(Strategy* strategy) { strategy_ = strategy; }

void RotateCommand::Execute(Operation role, double value) {
  strategy_->Execute(role, value);
}

// class MoveCommand
MoveCommand::MoveCommand(Strategy* strategy) { strategy_ = strategy; }

void MoveCommand::Execute(Operation role, double value) {
  strategy_->Execute(role, value);
}

// class ScaleCommand
ScaleCommand::ScaleCommand(Strategy* strategy) { strategy_ = strategy; }

void ScaleCommand::Execute(Operation role, double value) {
  strategy_->Execute(role, value);
}

}  // namespace s21