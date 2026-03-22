class MyQueue {

    private $s1 = [];
    private $s2 = [];

    function __construct() {
        // initialize stacks
    }

    // push → always s1 me
    function push($x) {
        array_push($this->s1, $x);
    }

    // pop → s2 se
    function pop() {
        if (empty($this->s2)) {
            while (!empty($this->s1)) {
                array_push($this->s2, array_pop($this->s1));
            }
        }
        return array_pop($this->s2);
    }

    // peek → s2 ka top
    function peek() {
        if (empty($this->s2)) {
            while (!empty($this->s1)) {
                array_push($this->s2, array_pop($this->s1));
            }
        }
        return end($this->s2);
    }

    // empty → dono empty hone chahiye
    function empty() {
        return empty($this->s1) && empty($this->s2);
    }
}
