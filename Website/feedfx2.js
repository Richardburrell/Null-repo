{
		var objToShrink;
		
		var heightNew = 0;
		
		var heightFinal = 28;
		var heightDiff = 0;
		
		var animateTime = 500; //ms
		var PPMSmult= 1;
		
		var fading = 0;
		var moving = 0;
		
		var FeedOrderArray = new Array();
		
		var globalFeedID = 0;
		var globalFeedNextId = 0;
	}
	function ToggleFeed(id)
	{
		if(fading == 0 && moving == 0)
		{
			if($("#feedtoggle_" + id ).html() == "-"){
				fading=1;
				globalFeedID = id;
				$("#feedcontent_" + id).fadeOut(animateTime)
				HideFeed($("#feed_" + id));
				_gaq.push(['_trackEvent','Feed', 'Close', 'Feed'+id]);
			}
			else
			{
				fading=1;
				globalFeedID = id;
				$("#feedtoggle_" + id ).innerHTML = "-";
				$("#feedcontent_" + id).fadeIn(animateTime)
				ShowFeed($("#feed_" + id));
				_gaq.push(['_trackEvent','Feed', 'Open', 'Feed'+id]);
			}
		}
	}

	
	function HideFeed(id)
	{
		objToShrink = id;
		heightNew = objToShrink.height(); 
		if(heightDiff == 0){
			heightDiff = heightNew - heightFinal;
		}
		if(heightNew > heightFinal)
		{
			heightNew = objToShrink.height() * 0.80;
			objToShrink.css("height",heightNew + "px");
		
			if(heightNew > heightFinal){
				setTimeout("HideFeed(objToShrink)",PPMSmult);
			}
			else{
				objToShrink.css("height",heightFinal)
					$("#feedtoggle_" + globalFeedID).html("+");
					fading=0;
				}
		}
		else
		{
			objToShrink.css("height",heightFinal,function(){
				$("#feedtoggle_" + globalFeedID).html("+");
				fading=0;
			});
			
		}
	}

	function ShowFeed(id)
	{
		objToShrink = id;
		heightNew = objToShrink.height();
		objToShrink.css("height","");
		calculatedHeight =  objToShrink.height();
		
		objToShrink.css("height",heightNew + "px");

		heightNew = objToShrink.height(); 
		if(heightDiff == 0){
			heightDiff = heightNew - heightFinal;
		}
		
		if(heightNew < calculatedHeight)
		{
			heightNew = objToShrink.height() * 1.60;
			objToShrink.css("height",heightNew + "px")
				if(heightNew < calculatedHeight){
					setTimeout("ShowFeed(objToShrink)");
				}
				else{
					objToShrink.css("height",calculatedHeight);
					$("#feedtoggle_" + globalFeedID).html("-");
					fading=0;	
				}
		}
		else
		{
			objToShrink.css("height",calculatedHeight);
			$("#feedtoggle_" + globalFeedID).html("-");
			fading=0;
		}
	}
	
	jQuery.fn.swap = function(b) {
	    b = jQuery(b)[0];
	    var a = this[0],
	        a2 = a.cloneNode(true),
	        b2 = b.cloneNode(true),
	        stack = this;

	    a.parentNode.replaceChild(b2, a);
	    b.parentNode.replaceChild(a2, b);

	    stack[0] = a2;
	    return this.pushStack( stack );
	};

	
	function MoveFeed(id,direction){
		if(!Array.indexOf){
			Array.prototype.indexOf = function(obj){
				for(var i=0; i<this.length; i++){
					if(this[i]==obj){
						return i;
					}
				}
				return -1;
			}
		}

		if(moving == 0)
		{
			moving = 1;
			FeedOrderArray = FeedOrder.split(",");
			globalFeedID = id.toString();
			var ThisIdIndex = FeedOrderArray.indexOf(globalFeedID)
			var NextIdIndex;
			if(direction=="d")
			{
				NextIdIndex = ThisIdIndex + 1;
				globalFeedNextID = FeedOrderArray[NextIdIndex];
				
				if(typeof(globalFeedNextID)!="undefined")
				{
					FeedOrderArray[ThisIdIndex] = globalFeedNextID;
					FeedOrderArray[NextIdIndex] = globalFeedID;
					FeedOrder = FeedOrderArray.join(",");
					$.cookie("FeedOrder", FeedOrder, { expires: 365 });
					if(fading == 0)
						{
							fading = 1;
							$("#feed_" + globalFeedID).fadeOut(animateTime, function(){
								$("#feed_" + globalFeedNextID).swap("#feed_" + globalFeedID);
								$("#feed_" + globalFeedID).fadeIn(animateTime, function(){
									fading=0;
									moving=0;
								});
								
							});
							
							_gaq.push(['_trackEvent','Feed', 'MoveDown', 'Feed'+id]);
						}
				}
				else
				{
					moving=0;
				}
			}
			else if(direction=="u")
			{
				NextIdIndex = ThisIdIndex - 1;
				globalFeedNextID = FeedOrderArray[NextIdIndex];
				if(typeof(globalFeedNextID)!="undefined")
				{
					FeedOrderArray[ThisIdIndex] = globalFeedNextID;
					FeedOrderArray[NextIdIndex] = globalFeedID;
					FeedOrder = FeedOrderArray.join(",");
					$.cookie("FeedOrder", FeedOrder, { expires: 365 });
					if(fading == 0)
						{
							fading = 1;
							$("#feed_" + globalFeedID).fadeOut(animateTime, function(){
								$("#feed_" + globalFeedNextID).swap("#feed_" + globalFeedID);
								$("#feed_" + globalFeedID).fadeIn(animateTime, function(){
									fading=0;
									moving = 0;
								});
							});
							_gaq.push(['_trackEvent','Feed', 'MoveUp', 'Feed'+id]);
						}
				}
				else
				{
					moving=0;
				}
			}
		}
		else
		{
			alert("Wait until the feeds are done moving before moving them again.  Thanks.");
			moving=0;
		}
	}

