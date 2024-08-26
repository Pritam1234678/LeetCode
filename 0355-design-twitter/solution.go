type Twitter struct {
	users     map[int][]tweet
	followers map[int]map[int]struct{}
}

type tweet struct {
	id int
	ts time.Time
}

func Constructor() Twitter {
	return Twitter{
		users:     make(map[int][]tweet),
		followers: make(map[int]map[int]struct{}),
	}
}
func (t *Twitter) PostTweet(userId int, tweetId int) {
	t.users[userId] = append(t.users[userId], tweet{tweetId, time.Now()})
}

func (t *Twitter) GetNewsFeed(userId int) []int {
	tweets := t.users[userId]
	for f := range t.followers[userId] {
		tweets = append(tweets, t.users[f]...)
	}
	sort.Slice(tweets, func(i, j int) bool {
		return tweets[i].ts.After(tweets[j].ts)
	})
	
	if len(tweets) > 10 {
		tweets = tweets[:10]
	}
	nf := make([]int, len(tweets))
	for i, tw := range tweets {
		nf[i] = tw.id
	}
	return nf
}

func (t *Twitter) Follow(followerId int, followeeId int) {
	if _, ok := t.followers[followerId]; !ok {
		t.followers[followerId] = make(map[int]struct{})
	}
	t.followers[followerId][followeeId] = struct{}{}
}

func (t *Twitter) Unfollow(followerId int, followeeId int) {
	delete(t.followers[followerId], followeeId)
}
