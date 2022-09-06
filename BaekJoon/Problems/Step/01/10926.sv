// 2022.09.05

module Q10926();

    reg [50*8:0] s;
    integer temp;

    initial begin
        temp = $fscanf(32'h8000_0000, "%s", s);
        // 32'h8000_0000 : descriptor that indicates STDIN
        // $fscanf() (maybe) returns EOF
        $display("%0s??!", s);
        $finish;
    end

endmodule