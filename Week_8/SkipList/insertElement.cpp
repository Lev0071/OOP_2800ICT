void SkipList::insertElement(int key) {
    auto current = header;
    vector<shared_ptr<Node>> update(MAXLVL + 1, nullptr);

    for (int i = level; i >= 0; i--) {
        while (current->forward[i] && current->forward[i]->getKey() < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];

    if (!current || current->getKey() != key) {
        int rlevel = randomLevel();

        if (rlevel > level) {
            for (int i = level + 1; i <= rlevel; i++) {
                update[i] = header;
            }
            level = rlevel;
        }

        auto n = make_shared<Node>(key, rlevel);
        for (int i = 0; i <= rlevel; i++) {
            n->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = n;
        }

        cout << "Successfully Inserted key " << key << "\n";
    }
}
