class NodeTrie{
    constructor(children,isWord){
        this.children = children;
        this.isWord = isWord;
    }
}

class PrefixTree {

    constructor() {
        this.root = new NodeTrie({}, false);
    }

    /**
     * @param {string} word
     * @return {void}
     */
    insert(word) {
        let current = this.root;
        for(let c of word){
            if(!current.children[c]){
                current.children[c] = new NodeTrie({}, false)
            }
            current = current.children[c];
        }

        current.isWord = true;
    }

    /**
     * @param {string} word
     * @return {boolean}
     */
    search(word) {
        let current = this.root;

        for(let c of word){
            if(!current.children[c]){
                return false;
            }

            current = current.children[c];
        }

        return current.isWord;
    }

    /**
     * @param {string} prefix
     * @return {boolean}
     */
    startsWith(prefix) {
        let current = this.root;

        for(let c of prefix){
            if(!current.children[c]){
                return false;
            }

            current = current.children[c];
        }

        return true;
    }
}
