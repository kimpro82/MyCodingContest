// 2022.09.05

module Q18108();

    integer by, diff = 2541 - 1998, temp;

    initial begin

        temp = $fscanf(32'h8000_0000, "%d", by);
        // 32'h8000_0000 : descriptor that indicates STDIN
        // $fscanf() (maybe) returns EOF
        $display("%0d", by - diff);
        $finish;
    end

endmodule