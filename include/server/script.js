function setSample(){
	const data = [];
	const URLtext = document.getElementById('url');
	const contest_type = document.getElementById('contest_type').value;
	let contest_number = document.getElementById('contest_number').value;
	let probrem_number = document.getElementById('probrem_number').value;
	if(URLtext.value!=""){
		data.push({
			"id":"url",
			"sample_in":URLtext.value
		});
	}else if(contest_type!="none" && contest_number!="" && probrem_number != ""){
		if(contest_number.length==1) contest_number="00"+contest_number;
		else if(contest_number.length==2) contest_number="0"+contest_number;
		probrem_number=probrem_number.toLowerCase();
		let gen_url = "https://atcoder.jp/contests/";
		const contest = contest_type+contest_number;
		gen_url+=contest+"/tasks/";
		gen_url+=contest+"_"+probrem_number;
		console.log(gen_url);
		data.push({
			"id":"url",
			"sample_in": gen_url
		});
	}
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
	document.getElementById('url').value='';
	document.getElementById('probrem_number').value='';
	for(let i=1;i<8;i++)
		document.getElementById(i).value='';
}

function clearForm(){
	document.getElementById('contest_type').value="none";
	document.getElementById('contest_number').value='';
	document.getElementById('probrem_number').value='';
}