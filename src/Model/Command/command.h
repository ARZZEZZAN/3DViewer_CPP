#ifndef CPP4_3DVIEWER_V2_0_3_SRC_MODEL_COMMAND_COMMAND_H_
#define CPP4_3DVIEWER_V2_0_3_SRC_MODEL_COMMAND_COMMAND_H_

#include "../Strategy/strategy.h"

namespace s21 {
class Command {
 public:
  virtual ~Command() {}
  virtual void Execute(Operation role, double value) = 0;

 protected:
  Strategy* strategy_;
};

class Invoker {
 public:
  void Execute(Command* command, Operation operation, double value);
};

class RotateCommand : public Command {
 public:
  RotateCommand(Strategy* strategy);

  void Execute(Operation role, double value) override;
};

class MoveCommand : public Command {
 public:
  MoveCommand(Strategy* strategy);

  void Execute(Operation role, double value) override;
};

class ScaleCommand : public Command {
 public:
  ScaleCommand(Strategy* strategy);

  void Execute(Operation role, double value) override;
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_3_SRC_MODEL_COMMAND_COMMAND_H_
