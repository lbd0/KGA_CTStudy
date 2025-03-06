for(int s : score) {
        q.push(s);
    }
    
    for(int i = 0; i < q.size(); i++) {
        cout << q.front();
        q.pop();
    }
    
    cout << score.size() % m << endl;
    
    for(int i = 0; i < score.size() % m; ++i) {
        q.pop();
    }
    
    for(int i = 0; i < q.size(); i++) {
        cout << q.front();
        q.pop();
    }
    
    