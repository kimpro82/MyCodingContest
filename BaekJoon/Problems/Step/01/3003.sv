// 2022.09.06

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