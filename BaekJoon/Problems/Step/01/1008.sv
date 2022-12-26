// 2022.09.05

module Q1008();
    
    real a, b, temp;

    initial begin
        temp = $fscanf(32'h8000_0000, "%d %d", a, b);
        // 32'h8000_0000 : descriptor that indicates STDIN
        // $fscanf() (maybe) returns EOF
        $display("%0.10f", a / b);
        $finish;
    end

endmodule