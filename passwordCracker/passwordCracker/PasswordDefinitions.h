//
//  PasswordDefinitions.h
//  Password-Example
//
//  Created by Jim Smith on 27/10/2015.
//  Copyright © 2015 James Smith. All rights reserved.
//

#ifndef PasswordDefinitions_h
#define PasswordDefinitions_h


/**
 @file PasswordDefinitions.h
 @brief  some defined params for Password
 */
//=======================================
/*here are some constant values that we will refer to
 * the beauty of using defines here is that now if I ever want ot change them I only need do so in one place
 */
#define N 8   ///< the size of the problem
#define SIZEOFSOLUTIONLIST 100000 ///< The size of the fixed arrays used to store open and closed lists
#define UNUSED '[' ///< An arbitrary value used to make the code clearer

#define NUM_VALID_CHARACTERS 62


#endif /* PasswordDefinitions_h */
