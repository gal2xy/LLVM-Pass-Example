# opt without llvm source code
在该分支下，编写的Pass通过opt执行，且脱离源码编写。


我们需要创建的Pass项目的目录结构如下：

```
<project dir>/
    |
    CMakeLists.txt
    <pass name>/
        |
        CMakeLists.txt
        Pass.cpp
        ...
```

CMakeLists.txt的填写和修改可参考当前目录下的gal2xyPassExample-opt（该目录下的build是编译后产生的）。也可以直接git当前项目直接使用。

Pass项目编译：

```shell
mkdir build
cd build
cmake ..
make
```

Pass使用：

```shell
opt -load yourpass.so -yourpassparam testfile ...
```

详细过程可见https://gal2xy.github.io/2024/04/22/LLVM%20and%20OLLVM/LLVM-Pass%E7%BC%96%E5%86%99/#4-2-%E8%84%B1%E7%A6%BB%E6%BA%90%E7%A0%81%E6%89%A7%E8%A1%8Cpass
