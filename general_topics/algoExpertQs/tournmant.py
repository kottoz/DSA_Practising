# Given an array of pairs.
# competitions = [[homeTeam, awayTeam]]
# 0 --> away team is won
# 1 --> home team is won
# exactly one team win.
# each team will compete against all other teams exactly one.
# tournment has at least two teams.
from collections import defaultdict
def tournamentWinner(competitions, results):
	# dict contains all win teams and it's score.
    record = {}
	# loop through results
    for result, competition in zip(results, competitions):
	# if home 
        if result:
		# if team is n't in dict add it
            if not(competition[0] in record):
                record[competition[0]] = 0
		    # increase winner 
            record[competition[0]] = record[competition[0]] + 1
	# else away
        else:
            if not(competition[1] in record):
                record[competition[1]] = 0
		    # increase away
            record[competition[1]] = record[competition[1]] + 1
    winner = max(record, key=record.get)
	
    return winner

comps = [
  ["HTML", "C#"],
  ["C#", "Python"],
  ["Python", "HTML"]
]

res = [0, 0, 1]

tournamentWinner(comps, res)