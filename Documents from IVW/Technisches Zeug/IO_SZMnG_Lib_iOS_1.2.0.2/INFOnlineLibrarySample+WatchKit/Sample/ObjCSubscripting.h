//
//  ObjCSubscripting.h
//  Sample
//
//  Created by Michael Ochs on 10/1/12.
//  Copyright (c) 2012 RockAByte GmbH. All rights reserved.
//

#if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_6_0

@interface NSDictionary(Subscripts)
- (id)objectForKeyedSubscript:(id)key;
@end

@interface NSMutableDictionary(Subscripts)
- (void)setObject:(id)obj forKeyedSubscript:(id <NSCopying>)key;
@end

@interface NSArray(Subscripts)
- (id)objectAtIndexedSubscript:(NSUInteger)idx;
@end

@interface NSMutableArray(Subscripts)
- (void)setObject:(id)obj atIndexedSubscript:(NSUInteger)idx;
@end


#if __IPHONE_OS_VERSION_MIN_REQUIRED >= __IPHONE_5_0

@interface NSOrderedSet (Subscripts)
- (id)objectAtIndexedSubscript:(NSUInteger)idx;
@end

@interface NSMutableOrderedSet (Subscripts)
- (void)setObject:(id)obj atIndexedSubscript:(NSUInteger)idx;
@end

#endif


#endif