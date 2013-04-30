$infile = $ARGV[0];
$outfile = $ARGV[1];

if(-e $infile){
    if(-e $outfile){
        printf("%s already exists, would you like to continue?\n", $outfile);
        $ans = <STDIN>;
        if($ans =~ /[nN]/){
            exit;
        }
    }

    open(INFILE, $infile);
    open(OUTFILE, ">".$outfile);

    while(<INFILE>){
        print OUTFILE $_;
    }
} else {
    printf("%s doesn't exist.\n", $infile);
}
