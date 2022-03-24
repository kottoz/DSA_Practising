def twoNumberSum(array, targetSum):
    cache = {}
    # basic corner for empty or one element array
    if len(array) <= 1:
        return []
        # go through array elements
    for item_index in range(len(array)):
		# if item is not in the cache add it with it's index
        item = array[item_index]
        if  item not in cache:
            cache.update({array[item_index]: item_index})
		# if subtraction of target and item in cache so i catch it
        subtraction = targetSum - item
        if (subtraction in cache) and (item_index != cache[targetSum - item]):
            return [subtraction, item]
		
	# corner case for 
    return []

if __name__ == '__main__':
    a = [3, 5, -4, 8, 11, 1, -1, 6]
    target = 10
    print(twoNumberSum(a, target))
