/* -*- c-file-style: "bsd" -*- * * $Id: rollsum.h,v 1.1 2000/05/22 08:53:41
   mbp Exp $ * * Copyright (C) 2000 by Martin Pool * * This program is free 
   software; you can redistribute it and/or modify * it under the terms of
   the GNU General Public License as published by * the Free Software
   Foundation; either version 2 of the License, or * (at your option) any
   later version. * * This program is distributed in the hope that it will
   be useful, * but WITHOUT ANY WARRANTY; without even the implied warranty
   of * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the * GNU
   General Public License for more details. * * You should have received a
   copy of the GNU General Public License * along with this program; if not,
   write to the Free Software * Foundation, Inc., 675 Mass Ave, Cambridge, MA 
   02139, USA. */


/* ROLLSUM_T contains the checksums that roll through the new version of the
   file as we see it.  We use this for two different things: searching for
   matches in the old version of the file, and also generating new-signature
   information to send down to the client.  */
struct hs_rollsum {
    int             havesum;	/* false if we've skipped & need to
				   recalculate */
    uint32_t        weak_sum, s1, s2;	/* weak checksum */
};

/* Define this to check all weak checksums the slow way.  As a debuggging
   assertion, calculate the weak checksum *in full* at every byte, and make
   sure it is the same.  This will be really slow, but it will catch problems 
   with rolling. */
#define HS_PAINFUL_HONESTY


int
                _hs_trim_sums(char const *p, hs_rollsum_t * rollsum,

			      int short_block);

int
                _hs_update_sums(char const *p, int full_block,
				int short_block, hs_rollsum_t * rollsum);

void            _hs_roll_reset(hs_rollsum_t * rollsum);