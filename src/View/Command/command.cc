#include "command.h"

namespace s21 {
// class Invoker
void Invoker::Execute(Command* command, Operation operation) {
  command->Execute(operation);
  delete command;
}

// class RotateCommand
RotateCommand::RotateCommand(Strategy* strategy) { strategy_ = strategy; }

void RotateCommand::Execute(Operation role) { strategy_->Execute(role); }

// class MoveCommand
MoveCommand::MoveCommand(Strategy* strategy) { strategy_ = strategy; }

void MoveCommand::Execute(Operation role) { strategy_->Execute(role); }

// class ColorCommand
ColorCommand::ColorCommand(Strategy* strategy) { strategy_ = strategy; }

void ColorCommand::Execute(Operation role) { strategy_->Execute(role); }

// class ScaleCommand
ScaleCommand::ScaleCommand(Strategy* strategy) { strategy_ = strategy; }

void ScaleCommand::Execute(Operation role) { strategy_->Execute(role); }

}  // namespace s21