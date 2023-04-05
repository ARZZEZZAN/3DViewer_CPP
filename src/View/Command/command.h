#ifndef CPP4_3DVIEWER_V2_0_2_SRC_VIEW_COMMAND_COMMAND_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_VIEW_COMMAND_COMMAND_H_

#include "StrategyActions/strategyActions.h"

namespace s21 {
class Command {
 public:
  virtual ~Command() {}
  virtual void Execute(Operation role) = 0;

 protected:
  Strategy* strategy_;
};

class RotateCommand : public Command {
 public:
  RotateCommand(Strategy* strategy);

  void Execute(Operation role) override;
};

class MoveCommand : public Command {
 public:
  MoveCommand(Strategy* strategy);

  void Execute(Operation role) override;
};

class ScaleCommand : public Command {
 public:
  ScaleCommand(Strategy* strategy);

  void Execute(Operation role) override;
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_2_SRC_VIEW_COMMAND_COMMAND_H_
