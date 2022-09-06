// 2022.09.05

module Q10430();
    
    integer a, b, c, temp;

    initial begin
        temp = $fscanf(32'h8000_0000, "%d %d %d", a, b, c);
        // 32'h8000_0000 : descriptor that indicates STDIN
        // $fscanf() (maybe) returns EOF
        $display("%0d", (a + b) % c);
        $display("%0d", ((a % c) + (b % c)) % c);
        $display("%0d", (a * b) % c);
        $display("%0d", ((a % c) * (b % c)) % c);
        $finish;
    end

endmodule