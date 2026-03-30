class Solution {
    
    canFinish(numCourses, prerequisites) {
        let indegree = Array(numCourses).fill(0);
        let adj = Array.from({ length: numCourses }, () => []);

        // ✅ CORRECTO: [a, b] significa b -> a
        for(let [a, b] of prerequisites) {
            indegree[a]++;    // a depende de b
            adj[b].push(a);   // arista b -> a
        }

        let q = new Queue();
        
        // Agregar nodos sin prerequisitos (indegree = 0)
        for(let i = 0; i < numCourses; i++){
            if(indegree[i] === 0){
                q.push(i);
            }
        }

        let processed = 0;
        
        while(!q.isEmpty()){
            let course = q.pop();
            processed++;

            // Procesar vecinos (cursos que dependen de este)
            for(let neighbor of adj[course]){
                indegree[neighbor]--;
                if(indegree[neighbor] === 0){
                    q.push(neighbor);
                }
            }
        }

        return processed === numCourses;
    }
}