{ npoints=$2; nunits=$3; sram=$4 }
{ key = npoints " " nunits " " sram }
{ print; print key }
{ ntests[key]++ }
{ printf("ntests['%s'] = %d\n", key, ntests[key]) }
{ print "" }

END {
    mem[0] = "1port"; mem[1] = "2port"; mem[2] = "dpump"
  
    # HEADER
    printf("       ")
    for (npoints=8; npoints <= 8192; npoints *= 2) {
        printf(" %4d", npoints)
    }
    print(""); print("")
    
    # BODY
    for (nunits=1; nunits <= 4; nunits *= 2) {
        for (i=0; i<=2; i++) {
            sram = mem[i]
            printf("%s-%s", nunits, sram)
            for (npoints=8; npoints <= 8192; npoints *= 2) {
                key = npoints " " nunits " " sram
                #               printf("ntests['%s'] = %d\n", key, ntests[key])
                
                if (ntests[key] == 0) { ntests[key] = "-" }
                printf(" %4s", ntests[key])
            }
            print ""
        }
        print ""
    }
}

