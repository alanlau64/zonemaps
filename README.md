The results of point query on 1 million size dataset are listed below. 

0% noise: Time taken to perform point queries from zonemap = 150804166 microseconds \
1% noise: Time taken to perform point queries from zonemap = 157682954 microseconds \
5% noise: Time taken to perform point queries from zonemap = 199889070 microseconds \
25% noise: Time taken to perform point queries from zonemap = 270700359 microseconds

For unknown reason, the query ran very slow on my own laptop, like one and a half hour for 0% noice or so. So I ran the code on SCC and got results above. However, it has already taken more than 1.5 hour to run 5 million database, so the results are not included. 

For range query, it only takes like 20000-30000 microseconds since the whole workload is only looped once. 