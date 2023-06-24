import snscrape.modules.twitter as sntwitter
import pandas as pd

hashtag = "#submarino"
min_likes = 0

tweets = []
for i, tweet in enumerate(sntwitter.TwitterSearchScraper(f'{hashtag}').get_items()):
    if i >= 1000:  # Scrape 1000 tweets
        break
    if tweet.likeCount >= min_likes:
        tweets.append([tweet.date, tweet.user.username, tweet.likeCount, tweet.sourceLabel, tweet.content])

# Convert the list of tweets to a DataFrame
tweets_df = pd.DataFrame(tweets, columns=["Date Created", "User", "Number of Likes", "Source of Tweet", "Tweet"])

print(tweets_df.head())
