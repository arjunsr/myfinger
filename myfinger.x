struct myfinger_in {
       char user_name[4096];
};

struct myfinger_out {
       char output[4096];
};

program MYFINGER_PROGRAM {
	version MYFINGER_VERSION {
		myfinger_out MYFINGER(myfinger_in) = 1; /* procedure number = 1 */
	} = 1 ; /* version number */
} = 0x31230000; /* program number */
