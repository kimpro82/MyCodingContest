// 2022.09.06

module Q2588();
    
    integer a;
    reg [3*8:0] b;
    integer i, prod, sum = 0, temp;

    initial begin
        temp = $fscanf(32'h8000_0000, "%d", a);
        temp = $fscanf(32'h8000_0000, "%s", b);
        // 32'h8000_0000 : descriptor that indicates STDIN
        // $fscanf() (maybe) returns EOF

        for (i = 0; i < 3; i = i + 1) begin
            prod = a * (b[i*8 +: 8] - 48);
            sum = sum + prod * (10**i);

            // test
            // $display("%0d %0d %0d %0d %0d", i, a, b[i*8 +: 8] - 48, prod, sum);

            $display("%0d", prod);
        end
        $display("%0d", sum);
        $finish;
    end

endmodule