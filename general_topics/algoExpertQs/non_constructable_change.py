def nonConstructibleChange(coins):
    # if coins is empty return 1
    if not len(coins):
        return 1
        # get max number index
    max_element = max(coins)
    max_index = coins.index(max_element)
    new_coins = coins.copy()
    del new_coins[max_index]
    # summ all numbers exept the max
    min_sum = sum(new_coins) + 1
    return min_sum

coins = [5, 7, 1, 1, 2, 3, 22]
nonConstructibleChange(coins)