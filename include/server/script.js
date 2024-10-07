function setSample(){
	const data = [];
	for(let i=1;i<8;i++){
		const textarea = document.getElementById(i);
		if(textarea&&textarea.value){
			data.push({
				"id":i,
				"sample_in": textarea.value
			});
		}
	}
	if(data.length>0){
		fetch('/conpro/sample_register',{
			method:'POST',
			headers:{ 'Content-Type':'application/json' },
			body:JSON.stringify(data)
		})
		.then(response => {
			if (response.ok) console.log('Data sent successfully');
			else console.error('Failed to send data');
		})
		.catch(error => { console.error('Error:', error); });
	}else console.log("No valid data to send");
}

function clearField(){
	for(let i=1;i<8;i++)
		document.getElementById(i).value='';
}