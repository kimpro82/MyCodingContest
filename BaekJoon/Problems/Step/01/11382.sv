// 11382. 꼬마 정민
// 2025.12.27

module Q11382();
    
    longint a, b, c, temp;  // longint: 64-bit signed integer

    initial begin
        temp = $fscanf(32'h8000_0000, "%d %d %d", a, b, c);
        // 32'h8000_0000 : descriptor that indicates STDIN
        // $fscanf() (maybe) returns EOF
        $display("%0d", a + b + c);
        $finish;
    end

endmodule
