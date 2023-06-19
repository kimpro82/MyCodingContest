## [BAEKJOON Online Judge](../../../../README.md#baekjoon-online-judge)

# 문제 > 단계별로 풀어보기 > 6. 심화 1

https://www.acmicpc.net/step/52

(2023.06.19) - `C++`  
(2022.09.06) - `SystemVerilog`


### **List**

- [25083. 새싹](#25083-새싹)
- [3003. BIJELE](#3003-bijele)
- []()
- []()
- []()
- []()

#### (Depreciated)
- []()


**※ Note**  

&nbsp;&nbsp; - All the codes of any language for the same problem have basically the same result.  
&nbsp;&nbsp; - Typical headers like the below are basically skipped, but they are noted seperately when there are any additional line.  
&nbsp;&nbsp;&nbsp;&nbsp; · `Bash` : `#!/bin/bash`  
&nbsp;&nbsp;&nbsp;&nbsp; · `C++` : `#include <iostream>` `#define endl '\n';` `using namespace std;`  
&nbsp;&nbsp;&nbsp;&nbsp; · `Golang` : `package main` `import "fmt"`  
&nbsp;&nbsp;&nbsp;&nbsp; · `SystemVerilog` : `module` `endmodule`.  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; * All the codes run on [JDoodle Online VERILOG Compiler IDE](https://www.jdoodle.com/execute-verilog-online/) as `Verilog` before submitted to [BOJ](https://www.acmicpc.net/) as `SystemVerilog`.  
&nbsp;&nbsp; - `R` : Some answers occur runtime errors with unknowable reason in the BOJ grading machine.  
&nbsp;&nbsp; - `Text` : Only possible problems that do not require input values are solved.  



## [25083. 새싹](#list)

```txt
         ,r'"7
r`-_   ,'  ,/
 \. ". L_r'
   `~\/
      |
      |
```

#### SystemVerilog (2022.09.05)
```sv
module Q25083();

    initial begin
        $display("         ,r'\"7");
        $display("r`-_   ,'  ,/");
        $display(" \\. \". L_r'");
        $display("   `~\\/");
        $display("      |");
        $display("      |");
        $finish;
    end

endmodule
```


## [3003. BIJELE](#list)

```txt
2 1 2 1 2 1
```
```txt
-1 0 0 1 0 7
```

#### SystemVerilog (2022.09.06)
```sv
module Q3003();

    reg [6*8:0] pieces = "112228";                                              // Can I enter this as an integer array?
    integer signed data[6:0];
    integer temp, i;

    initial begin
        // Input
        for (i = 0; i < 6; i = i + 1) begin
            temp = $fscanf(32'h8000_0000, "%d", data[i]);
            // 32'h8000_0000 : descriptor that indicates STDIN
            // $fscan() (maybe) returns EOF
        end

        for (i = 0; i < 6; i = i + 1) begin
            // test
            // $display("%0d %0d", pieces[(6-i)*8 - 8 +: 8] - 48, data[i]);

            $write("%0d ", $signed(pieces[(6-i)*8 - 8 +: 8] - 48) - data[i]);
        end
        $display();
        $finish;
    end

endmodule
```



## [](#list)

> 

> 

#### C++
```cpp

```

## [](#list)

> 

> 

#### C++
```cpp

```

## [](#list)

> 

> 

#### C++
```cpp

```

