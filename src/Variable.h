#ifndef VARIABLE_H
#define VARIABLE_H

struct VariableBlock {
  int x00;
  int x04;
  int x08;
  int x0c;
};

struct VariableLoadBlock {
  void load( VariableBlock &rkBlock ) {
    present[0] = true;
    present[1] = true;
    present[2] = true;
    present[3] = true;
    block.x00 = rkBlock.x00;
    block.x04 = rkBlock.x04;
    block.x08 = rkBlock.x08;
    block.x0c = rkBlock.x0c;
  }

  bool present[4];
  VariableBlock block;
};

#endif
