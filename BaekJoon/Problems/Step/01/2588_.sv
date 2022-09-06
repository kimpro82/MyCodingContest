// 2022.09.05

module Q2588();
    
    integer a;
    reg [3*8:0] b;
    integer i, conv, prod, sum, temp;

    initial begin
        temp = $fscanf(32'h8000_0000, "%d", a);
        temp = $fscanf(32'h8000_0000, "%c%c%c", b[0], b[8], b[16]);
        // 32'h8000_0000 : descriptor that indicates STDIN
        // $fscanf() (maybe) returns EOF

        begin
            for (i = 0; i < 3; i = i + 1)
                // conv = int'(b[(3-i-1)*8 -: 8]);
                // prod = a * conv * (10 ** i) ;
                // sum = sum + prod;

                // // test
                $display("%d %d %c", i, a, b[i*8 +: 8]);
                // $display("%d %d %d %d %d", i, a, int'(b[(3-i-1)*8 -: 8]), prod, sum);

                // $display("%d", prod);
        end
        $display("%d", sum);
        $finish;
    end

endmodule