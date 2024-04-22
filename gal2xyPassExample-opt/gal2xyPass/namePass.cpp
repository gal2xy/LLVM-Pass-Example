#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {
  struct namePass : public FunctionPass{
      static char ID;
      namePass() : FunctionPass(ID){}
      bool runOnFunction(Function &F) override {
          errs() << "Before namePass: " << F.getName() << '\n';
          llvm::MD5 hasher;
          llvm::MD5::MD5Result hash;
          hasher.update(F.getName());
          hasher.final(hash);
          SmallString<32> hexString;
          llvm::MD5::stringifyResult(hash, hexString);
          F.setName(hexString);
          errs() << "After namePass: " << F.getName() << '\n';
          return false;
      }
  };
}

char namePass::ID = 2;

static RegisterPass<namePass> X("namepass", "Welcome To namePass");
