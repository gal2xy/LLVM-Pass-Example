#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/IR/LegacyPassManager.h"

using namespace llvm;

namespace {
  struct logPass : public FunctionPass{
      static char ID;
      logPass() : FunctionPass(ID){}
      bool runOnFunction(Function &F) override {
          errs() << "logPass: ";
          errs().write_escaped(F.getName()) << '\n';
          return false;
      }
  };
}

char logPass::ID = 1;

static RegisterPass<logPass> X("logpass", "Welcome To logPass");

static RegisterStandardPasses Y(PassManagerBuilder::EP_EarlyAsPossible,
    [](const PassManagerBuilder &Builder, legacy::PassManagerBase &PM){
       PM.add(new logPass());
    }

);
